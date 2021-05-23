
  # Loading airquality dataset
  data("airquality")
  my_airquality_data <- airquality
 
  # Summarising dataset
  summary(my_airquality_data)

  
  # Data cleaning
  sum(is.na(my_airquality_data))
  
   # Finding out total no of NA in each column
   sapply(my_airquality_data, function(x)sum(is.na(x)))
 
   # Solution 1 to remove NA values : Omit rows containing NA value  
   copy <- airquality
   nrow(copy)

   nrow(na.omit(copy))
   
   # Solution 2 to remove NA values : Replace NA value with mean value 
   
   my_airquality_data$Ozone[is.na(my_airquality_data$Ozone)] <- as.integer(mean(my_airquality_data$Ozone, na.rm = TRUE))
   
   my_airquality_data$Solar.R[is.na(my_airquality_data$Solar.R)] <- as.integer(mean(my_airquality_data$Solar.R, na.rm = TRUE))
   
   # Checking if there are any NA values
   sum(is.na(my_airquality_data))
   
   
  # Data integration
  
   my_airquality_data_subset_1 <- my_airquality_data[1:10, c(2,3)]

   my_airquality_data_subset_2 <- my_airquality_data[1:10, c(4,5)]   
   
   cbind(my_airquality_data_subset_1, my_airquality_data_subset_2)

   
  # Data transformation

   copy$Month <- month.abb[copy$Month]

  
  # Data model building (regression model for prediction of Ozone value)   
   
   # Normalizing the dataset so that no particular attribute has more impact on clustering algorithm than others.
   normalize <- function(x){
      
      return((x-min(x))/(max(x)-min(x)))
   
   }
   
   # replace contents of dataset with normalized values
   my_airquality_data_normalized <- normalize(my_airquality_data) 
   str(my_airquality_data_normalized)    
   
   # Setting predictor attribute
   solar_R <- my_airquality_data_normalized[, "Solar.R"]
   
   # Setting target attribute
   ozone <- my_airquality_data_normalized[, "Ozone"]
   
   # Fitting linear model
   model_ozone_solar_R <- lm(ozone~solar_R)
   model_ozone_solar_R        # Gives values of y-intercept and slope         
   
   plot(ozone~solar_R)
   
   # Prediction of 'Ozone' when 'Solar.R'= 20
   p1 <- predict(model_ozone_solar_R, data.frame("solar_R" = 20))
   p1   
      
   
