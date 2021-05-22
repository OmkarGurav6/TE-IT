package weather;

import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class  TempMapper extends Mapper<LongWritable,Text,Text,IntWritable>
{
    public void map(LongWritable key,Text value,Context context)  throws IOException,InterruptedException {
       
    	String line = value.toString();
        String year = line.substring(15, 19);
        int temp = 9999;

        if (line.charAt(87)=='+') {
            temp = Integer.parseInt(line.substring(88, 92));
        } else {
            temp = Integer.parseInt(line.substring(87, 92));
        }

        if (temp != 9999) {
            context.write(new Text(year), new IntWritable(temp));
        }
    }
}