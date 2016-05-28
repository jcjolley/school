import javafx.scene.Scene;
import javafx.application.Platform;
import javafx.scene.layout.VBox;

public class Resize implements Runnable{

  @Override
  public void run() {
    Bold theBold = Bold.getInstance();
    Scene scene = theBold.getScene();
    VBox root = theBold.getRoot();
    try {
      while (!Thread.currentThread().isInterrupted()) {
        Platform.runLater(new Runnable() {
          @Override public void run() {

            root.setSpacing(root.getSpacing() + 1);
          }
        });
        Thread.sleep(100);
      }
    } catch (Exception e) {
      Platform.runLater(new Runnable() {
        @Override public void run() {
          root.setSpacing(40);
        }
      });
      Thread.currentThread().interrupt();
    }
    System.out.println("Ended Gracefully");
  }
}
