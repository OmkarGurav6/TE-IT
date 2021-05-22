package weather;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FileStatus;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class Driver {

		@SuppressWarnings("deprecation")
	    public static void main(String[] args) throws Exception{
	    //creating object of configuration class
	    Configuration c = new Configuration();
	    
	    //Assigning job to new configuration object
	    Job job = new Job(c);
	    
	    //setting jar class
	    job.setJarByClass(weather.Driver.class);
	    
	    job.setMapperClass(weather.TempMapper.class);
	    
	    job.setReducerClass(weather.TempReducer.class);
	    
	    job.setOutputKeyClass(Text.class);
	    job.setOutputValueClass(IntWritable.class);
		
	    //Adding a Path to the list of inputs
	    FileInputFormat.addInputPath(job, new Path(args[0]));
	    
	    //Setting the Path of the output directory 
	    FileOutputFormat.setOutputPath(job,new Path(args[1]));
		
	    //wait till job is completed
	    job.waitForCompletion(true);
		
		//file system object
		FileSystem fs = FileSystem.get(c);
		
		FileStatus[] status = fs.listStatus(new Path("hdfs://localhost:9000"+args[1]));
		FSDataInputStream fd = fs.open(status[1].getPath());
		
		String str = fd.readLine();
		
		float max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, temp;
        String minYear = null, maxYear = null;

        int pos = 0;
        
        while(str != null) {
        	
            String [] parts = str.split("\t");
            temp = Integer.parseInt(parts[1]);

            if(pos % 2 == 0)
            {
              if(temp > max) 
              {
                max = temp;
                maxYear = parts[0];
              }
            }
            else {
              if(temp < min) 
              {
                min = temp;
                minYear = parts[0];
              }
            }
            
            pos++;
            
            str = fd.readLine();
        }

        System.out.println("Maximum temperature : " + max/10 + " in the year " + maxYear);
        System.out.println("Minimum temperature : " + min/10 + " in the year " + minYear);
		
	}
}
