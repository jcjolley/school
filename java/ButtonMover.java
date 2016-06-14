import javafx.scene.control.Button;
import javafx.application.Platform;

public class ButtonMover implements Runnable{

  @Override
  public void run() {
    Bold theBold = Bold.getInstance();
    Button addBtn = theBold.getButton();
    try {
      while (!Thread.currentThread().isInterrupted()) {
        Platform.runLater(new Runnable() {
          @Override public void run() {
            addBtn.setText("A NEW NAME!!!");
          }
        });
        Thread.sleep(1000);
        Platform.runLater(new Runnable() {
          @Override public void run() {
            addBtn.setText("Add a Class");
          }
        });
        Thread.sleep(1000);
      }
    } catch (Exception e) {
      Thread.currentThread().interrupt();
    }
    System.out.println("Ended Gracefully");
  }
}
