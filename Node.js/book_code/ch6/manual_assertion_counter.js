exports.testPony = function(test) {
  var assertionCounter = 0; 
  if (false) {
    test.ok(false, 'This should not have passed.');
    assertionCounter++; 
  }
  test.ok(true, 'This should have passed.');
  assertionCounter++; 
  test.equal(
    assertionCounter,
    2, 
    'Not all assertions triggered.'
  ); 
  test.done();
}