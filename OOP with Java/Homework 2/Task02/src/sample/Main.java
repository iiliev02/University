package sample;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        Group group = new Group();
        Scene scene = new Scene(group, 300, 250);

        double width = scene.getWidth();
        double height = scene.getHeight();
        double partWidth = width / 20;
        double partHeight = height / 20;
        leftToDownSide(group, height, partHeight, partWidth);
        rightToUpperSide(group, width, partHeight, partWidth);
        downToRightSide(group, height, width, partHeight, partWidth);
        upperToLeftSide(group, partHeight, partWidth);

        primaryStage.setTitle("Canvas Demo");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void leftToDownSide(Group group, double height, double partHeight, double partWidth){
        for(int i = 0; i < 20; i++)
        {
            Line line = new Line(0, i * partHeight, (i + 1) * partWidth, height);
            line.setStroke(Color.ORANGE);
            line.setStrokeWidth(1);
            group.getChildren().add(line);
        }
    }
    public static void rightToUpperSide(Group group, double width, double partHeight, double partWidth){
        for(int i = 0; i < 20; i++)
        {
            Line line = new Line((i) * partWidth, 0, width, (i + 1) * partHeight);
            line.setStroke(Color.ORANGE);
            line.setStrokeWidth(1);
            group.getChildren().add(line);
        }
    }
    public static void downToRightSide(Group group, double height, double width, double partHeight, double partWidth){
        for(int i = 0; i < 20; i++)
        {
            Line line = new Line(i * partWidth, height, width, (19 - i) * partHeight);
            line.setStroke(Color.ORANGE);
            line.setStrokeWidth(1);
            group.getChildren().add(line);
        }
    }
    public static void upperToLeftSide(Group group, double partHeight, double partWidth){
        for(int i = 0; i < 20; i++)
        {
            Line line = new Line((20 - i) * partWidth, 0, 0, (i + 1) * partHeight);
            line.setStroke(Color.ORANGE);
            line.setStrokeWidth(1);
            group.getChildren().add(line);
        }
    }
    public static void main(String[] args) {
        launch(args);
    }
}
