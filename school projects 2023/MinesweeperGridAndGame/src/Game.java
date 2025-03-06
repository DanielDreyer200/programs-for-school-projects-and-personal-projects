import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseButton;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Random;

/**
 * Main driver class. Grid, button array, win/loss logic and game written by Dan. Timer written by Crystal.
 * Joining of code, timer refinement, bomb(), and other minor changes written by Nick.
 */

public class Game {
    private final Button[][] btns = new Button[10][10];
    private int[][] counts = new int[10][10];

    boolean blank = true;
    boolean number = false;
    boolean bomb = true;
    final int mine =10;
    int flagCount =10;

    Button contButton = new Button();
    Label label = new Label();
    Label curPlayerStats;
    Label clock = new Label();
    int second = 0;
    Timer timer;

    Label flags = new Label();



    public Scene getGameScene() {
        curPlayerStats = new Label();
        curPlayerStats.setText(appData.curPlayer.display());
        initBtnsArray(); //use initial button array function
        onClick(); //use on click
        Group root = new Group(); //creates a group
        root.getChildren().add(getGrid()); //adds grid to group
        contButton.setVisible(false);
        flags.setText("Flags Available: "+flagCount);

        timer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                second++;
                Platform.runLater(()->{ clock.setText("Game Time: " + appData.formatTime(second));
            });
        }});

        timer.start();

        VBox vbox = new VBox(curPlayerStats,clock,root,flags,contButton); //puts group and label ib vbox
        vbox.setAlignment(Pos.CENTER);
        Scene scene = new Scene(vbox, 1000, 800); //makes scene size


        checkNeighbor(); //opens check neighbor function

        return scene;
    }





    private Pane getGrid() {
        int i = 0;
        int c = 0;
        int x = 0;

        GridPane gridPane = new GridPane();


        for(Button[] b : btns) { //transfers 2d array to array

            for(Button v : b) { //transfers array to object

                if(c >= 10){
                    x++;
                    i=0;
                    c=0;
                    gridPane.add(v, i , x); //creates grid in grid pane of each button changing row based on what c equals

                }else{
                    gridPane.add(v, i , x); //creates grid in grid pane of each button

                }
                i++;
                c++;
                //works
                v.setPrefSize(40,40);
            }

        }
        return gridPane;
    }
    private void initBtnsArray() {
        for(int i = 0; i < btns.length; i++) {
            for(int c = 0; c < btns.length; c++) {
                btns[i][c] = new Button(" "); //labels each button to blank

            }

        }
    }
    private void onClick() { //all click actions of code


        for (int i = 0; i < btns.length; i++) {
            for (int c = 0; c < btns.length; c++) {
                int fc = c;
                int fi = i;


                btns[i][c].setOnAction(event -> { //for anybutton clicked


                    if( counts[fi][fc] == mine){ // only when both the array is equal to mine
                        btns[fi][fc].setDisable(true); // disable button
                        lostGame(); //go to lost game function
                    }
                    else if (counts[fi][fc] == 0) { //only when both the array is equal to blank represented as 0
                        btns[fi][fc].setText(counts[fi][fc] + "");  //text of number to button
                        btns[fi][fc].setDisable(true); // disable button
                        ArrayList<Integer> wave = new ArrayList<>(); //creates a list array that will be used in wave function
                        wave.add(fi * 100 + fc); //adds button clicked to list array
                        clear(wave); //go to clear function
                        checkWin(); //go to check win function
                    } else if (counts[fi][fc] > 0 && counts[fi][fc] < 10) { //only when both the array is equal to number represented as the specific number
                        btns[fi][fc].setText(counts[fi][fc] + ""); //text of number to button
                        btns[fi][fc].setDisable(true);// disable button
                        checkWin();//go to check win function
                    }
                });

                btns[i][c].setOnMouseClicked(event -> {//button on mouse click

                    if(event.getButton() == MouseButton.SECONDARY){ //event of mouse click equals right click
                        if(btns[fi][fc].getText() == "F" ) //if button text is labeled flag
                        {
                            btns[fi][fc].setText(" "); //set text to blank
                            flagCount++; //add flag count
                            flags.setText("Flags Available: "+flagCount);
                        }
                        else if(btns[fi][fc].isDisabled()){
//
                            flag(); //kinda usless at the moment, small part of code dont know if we need to fix/ do anything with
                            // ^This code will be redundant once GUI is added to place flag.img on buttons.
                        }
                        else if(0 < flagCount && flagCount<= 10){ // of flag count is over 0 and less then but equal too 10
                            btns[fi][fc].setText("F"); //label button with flag
                            flagCount--; // subtract flag count
                            flags.setText("Flags Available: "+flagCount);
                        }
                        label.setText(String.valueOf(flagCount)); // show flag count (testing purposes)

                    }
                });


            }
        }
    }
    //curently useless
    private void flag(){

        for (int i = 0; i < btns.length; i++) {
            for (int c = 0; c < btns.length; c++) {
                if(btns[i][c].getText() == "F"){
                    flagCount++;
                }
            }
        }
    }
    //clears all 0 in array
    private void clear(ArrayList<Integer> wave){


        if (wave.size() == 0) {
            return; //return statement that is ultimately useless, just there in case of errors
        } else {
            int x = wave.get(0) / 100;  //divides wave by 100 and sets it to x
            int y = wave.get(0) % 100;//remader of  wave by 100 and sets it to y
            wave.remove(0); //removes the value from wave

            //finner commets will be said once as they all do the same just in a different direction
            try {
                if (x > 0 && y > 0 && (btns[x - 1][y - 1].isDisabled() != true)) { //checks top left if not disabled
                    if(btns[x - 1][y - 1].getText() == "F" && (btns[x - 1][y - 1].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x - 1][y - 1].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x - 1][y - 1].setText(counts[x - 1][y - 1] + ""); //sets top left to array number
                    btns[x - 1][y - 1].setDisable(true); //disables button
                    if (counts[x - 1][y - 1] == 0) { // if top left is blank, add it to array to be done again
                        wave.add((x - 1) * 100 + (y - 1));
                    }


                }
            }catch(Exception ignored){

            }try{
                if (y > 0 && (btns[x][y - 1].isDisabled() != true)) {//checks left if not disabled
                    if(btns[x][y - 1].getText() == "F" && (btns[x][y - 1].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x][y - 1].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x][y - 1].setText(counts[x - 1][y - 1] + "");
                    btns[x][y - 1].setDisable(true);
                    if (counts[x][y - 1] == 0) {
                        wave.add(x * 100 + (y - 1));
                    }


                }
            }catch(Exception ignored){

            }
            try{
                if (x < counts.length - 1 && y > 0 && (btns[x + 1][y - 1].isDisabled() != true)) { //checks bottom left if not disabled
                    if(btns[x + 1][y - 1].getText() == "F" && (btns[x + 1][y - 1].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x + 1][y - 1].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x + 1][y - 1].setText(counts[x + 1][y - 1] + "");
                    btns[x + 1][y - 1].setDisable(true);
                    if (counts[x + 1][y - 1] == 0) {
                        wave.add((x + 1) * 100 + (y - 1));
                    }

                }
            }catch(Exception ignored){

            }
            try{
                if (x > 0 && y > 0 && (btns[x - 1][y].isDisabled() != true)) { //checks top middle if not disabled
                    if(btns[x - 1][y].getText() == "F" && (btns[x - 1][y].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x - 1][y].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x - 1][y].setText(counts[x - 1][y] + "");
                    btns[x - 1][y].setDisable(true);
                    if (counts[x - 1][y] == 0) {
                        wave.add((x - 1) * 100 + y);
                    }

                }
            }catch(Exception ignored){

            }
            try{
                if (x < counts.length - 1 && (btns[x + 1][y].isDisabled() != true)) { //checks bottom middle if not disabled
                    if(btns[x + 1][y].getText() == "F" && (btns[x + 1][y].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x + 1][y].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x + 1][y].setText(counts[x + 1][y] + "");
                    btns[x + 1][y].setDisable(true);
                    if (counts[x + 1][y] == 0) {
                        wave.add((x + 1) * 100 + y);
                    }

                }
            }catch(Exception ignored){

            }
            try{
                if (x > 0 && y < counts[0].length - 1 && (btns[x - 1][y + 1].isDisabled() != true)) { //checks top right if not disabled
                    if(btns[x - 1][y + 1].getText() == "F" && (btns[x - 1][y + 1].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x - 1][y + 1].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x - 1][y + 1].setText(counts[x - 1][y + 1] + "");
                    btns[x - 1][y + 1].setDisable(true);
                    if (counts[x - 1][y + 1] == 0) {
                        wave.add((x - 1) * 100 + (y + 1));
                    }

                }
            }catch(Exception ignored){

            }
            try{
                if (y < counts[0].length - 1 && (btns[x][y + 1].isDisabled() != true)) { //checks right if not disabled
                    if(btns[x][y + 1].getText() == "F" && (btns[x][y + 1].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x][y + 1].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x][y + 1].setText(counts[x][y + 1] + "");
                    btns[x][y + 1].setDisable(true);
                    if (counts[x][y + 1] == 0) {
                        wave.add(x * 100 + (y + 1));
                    }

                }
            }catch(Exception ignored){

            }

            try{
                if (x < counts.length - 1 && y < counts[0].length - 1 && (btns[x + 1][y + 1].isDisabled() != true)) { //checks bottom right if not disabled
                    if(btns[x + 1][y + 1].getText() == "F" && (btns[x + 1][y + 1].isDisabled() != true)) //if button text is labeled flag
                    {
                        btns[x + 1][y + 1].setText(" "); //set text to blank
                        flagCount++; //add flag count
                    }
                    btns[x + 1][y + 1].setText(counts[x + 1][y + 1] + "");
                    btns[x + 1][y + 1].setDisable(true);
                    if (counts[x + 1][y + 1] == 0) {
                        wave.add((x + 1) * 100 + (y + 1));
                    }

                }
                clear(wave); //re does clear
            }catch(Exception ignored){ //all exceptions are to allow it to continue even if error

            }

        }

    }
    //if player looses
    public void lostGame() {
        for (int x = 0; x < btns.length; x++) {
            for (int y = 0; y < btns[0].length; y++) { //gives a value based on button length
                if (counts[x][y] ==mine) {
                    btns[x][y].setText("X"); //display button number
                    btns[x][y].setDisable(true); //disable button
                }
                else {
                    btns[x][y].setText(counts[x][y] + ""); //display button number
                    btns[x][y].setDisable(true); //disable button
                }

            }
        }
        timer.stop();
        appData.curPlayer.losses += 1;
        appData.updatePlayer(appData.curPlayer);
        AppSave.updateFile();
        contButton.setVisible(true);
        contButton.setText("You lost. Continue to leaderboard."); //tells user they lost (will send to leaderboard screen
        contButton.setOnAction(event -> {
            DisplayAgent.switchToLeaderboard(false);
        });
    }

    //to check for winner
    public void checkWin() {
        boolean winner = true;

        for (int x = 0; x < counts.length; x++) {
            for (int y = 0; y < counts[0].length; y++) {
                if (counts[x][y] != mine && (btns[x][y].isDisabled() != true)) {//if array is not a mine and button is not disabled
                    winner = false; //set winner to false
                }
            }
        }
        if (winner) { //if winner is true
            timer.stop();
            for (int x = 0; x < btns.length; x++) {
                for (int y = 0; y < btns[0].length; y++) { //gives a value based on button length
                    btns[x][y].setDisable(true); //disable button
                    if (counts[x][y] == mine){
                        btns[x][y].setText("F");
                    }
                }
            }
            flags.setText("0");
            appData.curPlayer.wins += 1;
            appData.curPlayer.bestTime = Math.min(appData.curPlayer.bestTime, second);
            appData.updatePlayer(appData.curPlayer);
            AppSave.updateFile();
            contButton.setVisible(true);
            contButton.setText("You won. Continue to leaderboard.");
            contButton.setOnAction(event -> {
                DisplayAgent.switchToLeaderboard(true);
            });




        }
    }

    //checks neighboring buttons
    public void checkNeighbor(){

        ArrayList<Integer> list = new ArrayList<Integer>(); //makes list array

        for(int x =0; x< counts.length; x++){
            for(int y=0; y<counts[0].length; y++){
                list.add(x*100 +y); //adds every part of count array into new list array
            }
        }

        counts = new int[10][10]; //count array is a 10 x 10 grid

// Bomb Array creation - Nick Robison @ 645pm 5 May
        int bombCount = 0;
        Random rand = new Random();
        while(bombCount<10) {
            int rng1 = rand.nextInt(10);
            int rng2 = rand.nextInt(10);
            if (!(counts[rng1][rng2] == mine)) {
                counts[rng1][rng2] = mine;
                bombCount++;
            }

        }
        for(int x =0; x< counts.length; x++){
            for(int y=0; y<counts.length; y++){
                int neighbor = 0; //sets neighbor to 0
                //repetitive so will explain for one then say directions for all
                if(counts[x][y] != mine){ //if array is not a mine
                    if(x > 0 && y > 0 && counts[x - 1][y - 1] == mine) { //if top left is mine
                        neighbor++; //neighbor adds 1
                    }
                    if(y > 0 && counts[x][y - 1] == mine) {//if left is mine
                        neighbor++;
                    }
                    if(x < counts.length - 1 && y > 0 && counts[x + 1][y - 1] == mine) {//if bottom left is mine
                        neighbor++;
                    }
                    if(x > 0 && counts[x - 1][y] == mine) {//if top middle is mine
                        neighbor++;
                    }
                    if(x < counts.length - 1 && counts[x + 1][y] == mine) { //if bottom middle is mine
                        neighbor++;
                    }
                    if(x > 0 && y < counts[0].length - 1 && counts[x - 1][y + 1] == mine) { //if top right is mine
                        neighbor++;
                    }
                    if(y < counts[0].length - 1 && counts[x][y + 1]== mine) { //if right is mine
                        neighbor++;
                    }
                    if(x < counts[0].length - 1 && y < counts[0].length - 1 && counts[x + 1][y + 1]== mine) {//if bottom right is mine
                        neighbor++;
                    }
                    counts[x][y] = neighbor; //the array variable = neighbors count
                }
            }
        }
    }
}
