package fxtimer;

import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.util.Duration;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.Border;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;


import java.util.*;




public class hangman extends Application
{
    String words[] = {"FRIENDS" ,"THE GAME IS WON", "SPACE", "CONQUERORS", "WINNERS", "HELLO", "HAPPINESS","LIVE"};

    Random random = new Random();

    String choice = words[random.nextInt(8)];



    Text text = new Text();
    String[] hidden = choice.split("");
    String[] replace = choice.replaceAll("[A-Z]","-").split("");


    String chance;
    String lock;
    Button[] buttonsArray = new Button[]{
            new Button("A"),
            new Button("B"),
            new Button("C"),
            new Button("D"),
            new Button("E"),
            new Button("F"),
            new Button("G"),
            new Button("H"),
            new Button("I"),
            new Button("J"),
            new Button("K"),
            new Button("L"),
            new Button("M"),
            new Button("N"),
            new Button("O"),
            new Button("P"),
            new Button("Q"),
            new Button("R"),
            new Button("S"),
            new Button("T"),
            new Button("U"),
            new Button("V"),
            new Button("W"),
            new Button("X"),
            new Button("Y"),
            new Button("Z")};


    int startTime =3;
    Timeline timeline;

    Label timerLabel = new Label();
    Label timerLabel1 = new Label();
    IntegerProperty timMinutes = new SimpleIntegerProperty(startTime);
    IntegerProperty timSec = new SimpleIntegerProperty(0);

    public static void main(String[]args){
        launch(args);
    }



    public void start(Stage Stage) throws Exception {


        Button button = new Button("uh oh");

        timerLabel.textProperty().bind(timMinutes.asString());
        timerLabel1.textProperty().bind(timSec.asString());

        button.setOnAction(new EventHandler<ActionEvent>() {


            public void handle(ActionEvent event) {
                if (timeline != null) {
                    timeline.stop();
                }

                timeline = new Timeline();
                timeline.getKeyFrames().add(
                        new KeyFrame(Duration.minutes(startTime+1),
                                new KeyValue(timMinutes, 0)));
                timeline.playFromStart();
                // Button event handler code goes here . . .
            }
        });





        
        text.setText(Arrays.toString(replace));

        text.setStyle("-fx-font-size: 5em; ");







        for(int i =0; i<26; i++){
            Button buttonOfficial = buttonsArray[i];
            buttonsArray[i].setStyle("-fx-font-size: 2em; ");
            buttonsArray[i].setPadding(new Insets(10));

            if(choice.contains(buttonsArray[i].getText())) {
                buttonOfficial.setOnAction(event -> buttonPressed1(event));


                if (buttonsArray[i].isPressed()) {


                }





            }else{
                buttonOfficial.setOnAction(event -> buttonPressed2(event));
            }

        }













        HBox hbox1 = new HBox();
        hbox1.getChildren().addAll(buttonsArray);

        hbox1.setAlignment(Pos.CENTER);

        timerLabel.setStyle(" -fx-font-size: 5em; ");


        VBox vbox = new VBox(text,hbox1, button,timerLabel);

        vbox.setAlignment(Pos.CENTER);

        Scene scene = new Scene(vbox,1500,500);

        Stage.setScene(scene);

        Stage.show();
    }

    public void buttonPressed1(ActionEvent event) {
        Button button1 = (Button) event.getSource();

        button1.setDisable(true);

        for(int i =0; i<hidden.length; i++) {

            if (button1.getText().equals(hidden[i])){
                replace[i] = replace[i].replace("-", button1.getText());

                System.out.print(hidden[i]);
                text.setText(Arrays.toString(replace));
            }



        }
        button1.setText("yes");

        button1.setStyle("-fx-background-color: #00ff00; -fx-font-size: 2em; ");

        button1.setPadding(new Insets(10));




    }
    public void buttonPressed2(ActionEvent event) {
    Button button1 = (Button) event.getSource();
    button1.setText("no");
    button1.setDisable(true);
    button1.setStyle("-fx-background-color: #Ff0000; -fx-font-size: 2em; ");




    }


    public void replaced(ActionEvent event){

        for(int i =0; i<26; i++) {




        }


    }
}
