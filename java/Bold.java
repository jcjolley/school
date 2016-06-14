//javaFX stuff
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.stage.FileChooser;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.control.ListView;
import javafx.scene.layout.Priority;
import javafx.scene.input.KeyEvent;
import javafx.geometry.HPos;
import javafx.geometry.VPos;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.Region;
import javafx.scene.paint.Color;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.scene.layout.Region;
import java.util.ArrayList;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import java.util.Collections;
import javafx.geometry.Insets;

//file stuff
import java.io.File;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;


public class Bold extends Application {
  private Scene scene;
  private TextField inputField;
  private Button addBtn;
  private Button runThreadBtn;
  private Button stopThreadBtn;
  private VBox root;
  private Label label;
  private ListView<Runnable> lvClasses;
  private ObservableList<Runnable> olClasses;
  private ListView<Thread> lvThreads;
  private ObservableList<Thread> olThreads;


  private static Bold instance;
  public static Bold getInstance() {
    return instance;
  }

  public Button getButton() {
    return addBtn;
  }

  public Scene getScene() {
    return scene;
  }

  public VBox getRoot() {
    return root;
  }
  /**
  * Method start
  * Initializes the GUI
  */
  @Override
  public void start(Stage stage) {
    synchronized (this) {
      instance = this;
      label = new Label("Please enter a Runnable class name:");
      inputField = new TextField();
      addBtn = new Button("Add Class");
      root = new VBox();
      lvClasses = new ListView<Runnable>();
      olClasses = FXCollections.observableArrayList();
      lvThreads = new ListView<Thread>();
      olThreads = FXCollections.observableArrayList();
      runThreadBtn = new Button("Run Thread");
      stopThreadBtn = new Button("Gracefully End Thread");
      //handle the button press.
      addBtn.setOnAction(new EventHandler<ActionEvent>() {
        @Override
        public void handle(ActionEvent event) {
          addClass();
          inputField.setText("");
        }
      });

      runThreadBtn.setOnAction(new EventHandler<ActionEvent>() {
        @Override
        public void handle(ActionEvent event) {
          //create a new thread with the class in the list
          Thread newThread = new Thread((Runnable)lvClasses.getSelectionModel().getSelectedItem());

          olThreads.addAll(newThread);
          //add thread to thread list
          lvThreads.setItems(olThreads);
          //run thread
          newThread.start();
        }
      });


      stopThreadBtn.setOnAction(new EventHandler<ActionEvent>() {
        @Override
        public void handle(ActionEvent event) {
          //create a new thread with the class in the list
          Thread stopThread = lvThreads.getSelectionModel().getSelectedItem();
          olThreads.remove(lvThreads.getSelectionModel().getSelectedIndex(),
                           lvThreads.getSelectionModel().getSelectedIndex() + 1);
          lvThreads.setItems(olThreads);
          stopThread.interrupt();

        }
      });

      //setup our layout
      setupLayout(stage);

      //Create a new scene of type Browser (which we create below)
      //and with the background color specified
      scene = new Scene(root, 700, 500);

      //Set this scene as the current scene on stage
      stage.setScene(scene);


      //Show the stage to the world!  (make it visible)
      stage.show();
    }
  }

  public void setupLayout(Stage stage) {
    stage.setTitle("Boldness Exploration");

    lvThreads.setMinWidth(80);
    lvThreads.setMinHeight(125);
    lvClasses.setMinWidth(80);
    lvClasses.setMinHeight(125);

    VBox vbox1 = new VBox();
    vbox1.getChildren().add(label);
    vbox1.getChildren().add(inputField);
    vbox1.getChildren().add(addBtn);

    root.getChildren().add(vbox1);
    HBox hbox1 = new HBox();
    VBox vbox2 = new VBox();
    VBox vbox3 = new VBox();

    vbox2.getChildren().add(lvClasses);
    vbox2.getChildren().add(runThreadBtn);

    vbox3.getChildren().add(lvThreads);
    vbox3.getChildren().add(stopThreadBtn);

    hbox1.getChildren().add(vbox2);
    hbox1.getChildren().add(vbox3);

    root.getChildren().add(hbox1);

    vbox1.setSpacing(10);
    vbox2.setSpacing(10);
    vbox3.setSpacing(10);
    root.setSpacing(40);
    hbox1.setSpacing(40);
    root.setPadding(new Insets(20,80,40,80));
}

  public void addClass() {
    inputField.getText();
    try {
      Runnable newClass = (Runnable)Class.forName(inputField.getText()).newInstance();
      olClasses.addAll(newClass);
      lvClasses.setItems(olClasses);
    } catch (Exception e){
      e.printStackTrace();
      e.getMessage();
    }
    return;
  }
  /**
  * Method main
  * Our driver program.  Gadzooks! Robin, why don't you drive for once?
  */
  public static void main(String args[]) {
    launch(args);
  }
}
