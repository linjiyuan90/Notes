var app = connect();

app.use(connect.basicAuth(function(user, pass, callback){
  User.authenticate({ user: user, pass: pass }, gotUser);

  function gotUser(err, user) {
    if (err) return callback(err);
    callback(null, user);
  }
}));
