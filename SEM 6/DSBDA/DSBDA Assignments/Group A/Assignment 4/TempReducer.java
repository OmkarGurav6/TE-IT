package weather;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class TempReducer extends Reducer<Text, IntWritable, Text, IntWritable> {

    public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {

        int max = -9999;
        int min = 9999;

        for(IntWritable value : values) {
        	
            if(value.get() < min)
                min = value.get();
            if(value.get() > max)
                max = value.get();
            
        }

        context.write(key, new IntWritable(max));
        context.write(key, new IntWritable(min));
    }

}
