package log;

import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class LogMapper extends Mapper <LongWritable,Text,Text,IntWritable> {
	
	public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException {
		
		String line = value.toString();    
        StringTokenizer tokenizer = new StringTokenizer(line);  
        
        con.write(new Text((tokenizer.nextToken())),new IntWritable(1));
        
	}
}
