deleteTest(function() {
  addTest(function() {
    todosUnfinishedCheckTest(function() {
      console.log( 
        'Completed '
          + testsCompleted
          + ' of ' + testsStarted
          + ' tests.'
      );
      todoDb.close(); 
    });
  });
});