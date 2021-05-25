
  zipf <- "C:/Users/DELL/Downloads/Facebook_metrics.zip"
 
  OutDir <- "C:/Users/DELL/Downloads/Facebook_metrics"
  
  
    unzip(zipf, exdir = OutDir)
    
    Facebook_Data <- read.csv("C:/Users/DELL/Downloads/Facebook_metrics/dataset_Facebook.csv", sep = ";")
    
    # Subsetting dataframe
    Subset_data <- Facebook_Data[1:7, 1:8]
    head(Subset_data)
    
    my_data <- Facebook_Data[, 1:4]
    # Merging dataframes using common column
    Merged_data <- merge(Subset_data, my_data, by = "Type")
    View(Merged_data)
    
    # rbind
    rbind_data_1 <- Facebook_Data[1:40,]
    rbind_data_2 <- Facebook_Data[51:80,]
    
    rbind_data <- rbind(rbind_data_1, rbind_data_2)
    View(rbind_data)
    
    # cbind
    cbind_data_1 <- Facebook_Data[1:40, 1:4]
    cbind_data_2 <- Facebook_Data[1:40, 5:8]
    
    cbind_data <- cbind(cbind_data_1, cbind_data_2)
    View(cbind_data)
    
    # Sorting dataframe on basis of likes using order()
    Likes_sorted_descending <- Facebook_Data[order(Facebook_Data$like, decreasing = "True"), c(1,2,3,4,17) ]
    head(Likes_sorted_descending)
    
    # Transposing dataframe
    transpose_data <- t(Subset_data)
    View(transpose_data)
    
    
    library("reshape")
    # Wide format to long format 
    molten_data <- melt(Subset_data, id = c("Type","Category"))
    View(molten_data)  
    
    # Long format to wide format 
    cast_data <- cast(molten_data, fun.aggregate = max)
    View(cast_data)
    
