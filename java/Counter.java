public class Counter implements Runnable{

  @Override
  public void run() {
    try {
      while (!Thread.currentThread().isInterrupted()) {
        for (int i = 0; i < 5000; i++) {
          System.out.println(i);
          Thread.sleep(10);
        }
      }
    } catch (Exception e) {
      Thread.currentThread().interrupt();
    }
    System.out.println("Ended Gracefully");
  }
}
