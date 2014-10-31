
if a mapepr will run too long (>= 600s), need to call
context.progress() to tell jobtracker the status.

## job
   : job.setSpeculativeExecution(false);  // set to false because we write to HBase
## ToolRunner
   ToolRunner will get the GenericOptions, so you don't have to parse
   it by yourself.
   : ToolRunner.run(tool, args);
   
# task side-effect files
* hdfs has a mechanism where each mapper, reduce can write to its temporary
  files, if success, **promote** to output dir
* the temporary dir is `${mapred.work.output.dir}` while the output is
  `${mapred.output.dir}`
* if speculative tasks are writing a same file, since there can be only one
  writer, the other writers will get a exception
* use this mechanism, then the success task can move the file to the target
  output
* can write a committer to do this work (FileOutputCommitter)


# mapreduce
## split
* one file may be split as serveral splits, one split for one mapper
* There is something called **CombineFileFormat** to combine serveral file as
  one split; Or write several files to one sequencefile
* to get the filename of current record/split:
```
FileSplit fileSplit = (FileSplit)context.getInputSplit();
String filename = fileSplit.getPath().getName();
// hbase
TableSplit currentSplit = (TableSplit)context.getInputSplit();
byte[] tableName = currentSplit.getTableName();
```
