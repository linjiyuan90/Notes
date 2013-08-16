var ejs = require('ejs')
  , fs = require('fs')
  , http = require('http')
  , filename = './template/students.ejs'; 

var students = [ 
  {name: 'Rick LaRue', age: 23},
  {name: 'Sarah Cathands', age: 25},
  {name: 'Bob Dobbs', arg: 37}
];

var server = http.createServer(function(req, res) { 
  if (req.url == '/') {
    fs.readFile(filename, function(err, data) { 
      var template = data.toString();
      var context = {students: students};
      var output = ejs.render(template, context); 
      res.setHeader('Content-type', 'text/html');
      res.end(output); 
    });
  } else {
    res.end('Not found', 404);
  }
});

server.listen(8000);
