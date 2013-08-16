var db = {
  users: [
      { name: 'tobi' }
    , { name: 'loki' }
    , { name: 'jane' }
  ]
}; 

function users(req, res, next) {
  if (req.url.match(/^\/user\/(\d+)/)) {
    var user = db.users[RegExp.$1];
    if (user) {
      res.setHeader('Content-Type', 'application/json');
      res.end(JSON.stringify(user));
    } else {
      var err = new Error('User not found');
      err.notFound = true;
      next(err);
    }
  } else {
    next();
  }
}
