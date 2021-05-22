
package words;

import org.apache.hadoop.fs.Path;    
import org.apache.hadoop.io.IntWritable;    
import org.apache.hadoop.io.Text;    
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;    
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;    
import org.apache.hadoop.mapreduce.Job;        
import org.apache.hadoop.conf.Configuration;

public class Driver {
	
	@SuppressWarnings("deprecation")
    public static void main(String[] args) throws Exception{
    //creating object of configuration class
    Configuration c = new Configuration();
    
    //Assigning job to new configuration object
    Job job = new Job(c);
    
    //setting jar class
    job.setJarByClass(words.Driver.class);
    
    job.setMapperClass(words.WordMapper.class);
    
    job.setReducerClass(words.WordReducer.class);
    
    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(IntWritable.class);
       
    //Adding a Path to the list of inputs
    FileInputFormat.addInputPath(job, new Path(args[0]));
    
    //Setting the Path of the output directory 
    FileOutputFormat.setOutputPath(job,new Path(args[1]));
    
    //wait till job is completed
    System.exit(job.waitForCompletion(true)?0:1);
}
	
}
