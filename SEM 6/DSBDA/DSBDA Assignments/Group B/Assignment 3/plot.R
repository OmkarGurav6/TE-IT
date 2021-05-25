
  # Facebook Dataset  

  File <- "C:/Users/DELL/Downloads/Facebook_metrics/dataset_Facebook.csv"

  
  if(! file.exists(File)){
    
    zipf <- "C:/Users/DELL/Downloads/Facebook_metrics.zip"
    
    OutDir <- "C:/Users/DELL/Downloads/Facebook_metrics"
    
    
    unzip(zipf, exdir = OutDir)
    
  }
  
  Facebook_data <- read.csv("C:/Users/DELL/Downloads/Facebook_metrics/dataset_Facebook.csv", sep = ";")

  
  library("ggplot2")
  
  # Scatterplot
  facebook_scatterplot <- ggplot(Facebook_data, aes(x = Lifetime.Post.Total.Reach, y = Lifetime.Post.Total.Impressions,
                                                    color = Type)) + 
                          geom_point(size = 3)
  facebook_scatterplot
  
  
  # Barplot
  facebook_barplot <- ggplot(Facebook_data, aes(x = Category, fill = Type)) + geom_bar(width = 0.25)  
  facebook_barplot
  
  
  # Boxplot
  facebook_boxplot <- ggplot(Facebook_data, aes(x = share, y = like, fill = Type)) + 
                      geom_boxplot() + coord_cartesian(ylim = c(0, 1000))
  facebook_boxplot

  
  # Piechart
  ggplot(Facebook_data, aes(x = "", y = comment, fill = Type)) +
  geom_bar(stat = "identity", width = 0.2 ) + coord_polar("y")
  
  
  # Lineplot
  facebook_lineplot <- ggplot(Facebook_data, aes(x = Lifetime.Post.Total.Reach, 
                                                 y = Lifetime.Post.Total.Impressions,
                                                 color = Type)) + geom_line(size = 2)
  facebook_lineplot  
  
  
  
  # airquality Dataset  
  
  data("airquality")
  my_airquality_data <- airquality
  my_airquality_data$Month <- month.abb[my_airquality_data$Month]
    
  # Scatterplot
  airquality_scatterplot <- ggplot(my_airquality_data, aes(x = Solar.R, y = Ozone,
                                                           color = Month)) + geom_point(size = 3)  
  airquality_scatterplot
  
  
  # Barplot
  airquality_barplot <- ggplot(my_airquality_data, aes(x = Temp, fill = Month)) + geom_bar(width = 0.35)  
  airquality_barplot

  
  # Boxplot
  airquality_boxplot <- ggplot(my_airquality_data, aes(x = Temp , y = Ozone, fill = Month)) + 
                        geom_boxplot()
  airquality_boxplot
  
  # Piechart
  ggplot(my_airquality_data, aes(x = "", y = Ozone, fill = Month)) +
  geom_bar(stat = "identity", width = 0.2 ) + coord_polar("y")
  
  # Lineplot
  airquality_lineplot <- ggplot(my_airquality_data, aes(y = Wind, 
                                x = Ozone, color = Month)) + geom_line(size = 2)
  airquality_lineplot  
  
  