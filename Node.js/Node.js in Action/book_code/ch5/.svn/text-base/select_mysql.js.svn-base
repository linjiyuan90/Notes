client.query(
  "SELECT * FROM users",
  function(err, results, fields) {
    if (err) throw err;

    for (var index in results) {
      console.log(results[index].name);
    }
    client.end();
  }
);