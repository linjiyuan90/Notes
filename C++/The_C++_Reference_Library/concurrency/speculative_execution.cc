
int quickComputation();
int accurateComputation();

// outside declared because lifetime of accurateComputation()
// might exceed lifetime of bestResultInTime()
// it seems that wherever f is, the parent thread will wait for it?
std::future<int> f;

int bestResultInTime() {
  // define time slot to get the answer:
  auto tp = std::chrono::system_clock()::now() + std::chrono::minute(1);

  // start both a quick and an accurate computation:
  f = std::async(std::launch::async, accurateComputation);
  int guess = quickComputation();

  // give accurate computation the rest of the time slot:
  std::future_status s = f.wait_until(fp);

  // return the best computation result we have:
  if (s == std::future_status::ready) {
    return f.get();
  } else {
    return guess;  // accurateComputation() continues --! how to stop it?
  }
}

