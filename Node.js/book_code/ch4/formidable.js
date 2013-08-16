...
  var form = new formidable.IncomingForm;

  form.on('field', function(field, value){
    console.log(name);
    console.log(value);
  });

  form.on('file', function(name, file){
    console.log(field);
    console.log(file);
  });

  form.on('end', function(){
    res.end('upload complete!');
  });

  form.parse(req);
...
