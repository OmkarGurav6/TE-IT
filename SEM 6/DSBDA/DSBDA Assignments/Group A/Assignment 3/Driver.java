package log;

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
	    job.setJarByClass(log.Driver.class);
	    
	    job.setMapperClass(log.LogMapper.class);
	    
	    job.setReducerClass(log.LogReducer.class);
	    
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
		String ip = "";
		int max = 0;
		
		while(str != null)
		{
			
			String parts[] = str.split("\t");
			
			if(max<Integer.parseInt(parts[1])) {
				
				max = Integer.parseInt(parts[1]);
				ip = parts[0];
			}	
			
    		str = fd.readLine();
    	}
		
		System.out.println("IP address : " + ip);
		System.out.println("No. of occurrences : " + max);
	}
}