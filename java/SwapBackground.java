import javafx.scene.Scene;
import javafx.application.Platform;

public class SwapBackground implements Runnable{

  @Override
  public void run() {
    Bold theBold = Bold.getInstance();
    Scene scene = theBold.getScene();
    try {
      while (!Thread.currentThread().isInterrupted()) {
        Platform.runLater(new Runnable() {
          @Override public void run() {
            //load our CSS file for this stage
            scene.getStylesheets().add("mycss.css");
          }
        });
        Thread.sleep(1000);
        Platform.runLater(new Runnable() {
          @Override public void run() {
            scene.getStylesheets().remove("mycss.css");          }
        });
        Thread.sleep(1000);
      }
    } catch (Exception e) {
      Thread.currentThread().interrupt();
    }
    System.out.println("Ended Gracefully");
  }
}
