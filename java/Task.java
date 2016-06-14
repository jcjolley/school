public class Task implements Runnable{
  protected volatile boolean done = false;
  public void endThread() {
    done = true;
  }
  public void run(){
    System.out.println("Default Task");
  }
}
