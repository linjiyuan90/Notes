var connect = require('connect'); 
var app = connect()
  .use(logger)
  .use(restrictFileAccess) 
  .use(serveStaticFiles)
  .use(hello);