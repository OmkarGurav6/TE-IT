
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
   
   my_airquality_data$Ozone[is.na(my_airquality_data$Ozone)] <- mean(my_airquality_data$Ozone, na.rm = TRUE)
   
   my_airquality_data$Solar.R[is.na(my_airquality_data$Solar.R)] <- mean(my_airquality_data$Solar.R, na.rm = TRUE)
   
   # Checking if there are any NA values
   sum(is.na(my_airquality_data))
   
   
  # Data integration
  
   
   
   
   
   
   