function restrict(req, res, next) {
  var authorization = req.headers.authorization;
  if (!authorization) return next(new Error('Unauthorized'));

  var parts = authorization.split(' ')
    , scheme = parts[0]
    , auth = new Buffer(parts[1], 'base64').toString().split(':')
    , user = auth[0]
    , pass = auth[1];

  authenticateWithDatabase(user, pass, function (err) {
    if (err) return next(err);
    next();
  });
}
