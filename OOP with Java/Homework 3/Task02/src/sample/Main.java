package sample;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Group group = new Group();
        Scene scene = new Scene(group, 300, 250);
        double width = scene.getWidth();
        double height = scene.getHeight();
        double partWidthLine = width / 12.0;
        double partHeightLine = height / 12.0;
        for(int i = 0; i < 5; i++)
        {
            downLine(group, width, height, i * partWidthLine,i * partHeightLine, i * partWidthLine, (i + 1) * partHeightLine);
            leftLine(group, width, height, i * partWidthLine,(i + 1) * partHeightLine, (i + 1) * partWidthLine, (i + 1) * partHeightLine);
            upLine(group, width, height, (i + 1) * partWidthLine,(i + 1) * partHeightLine, (i + 1) * partWidthLine, (i + 1) * partHeightLine);
            rightLine(group, width, height, (i + 1) * partWidthLine,(i + 1) * partHeightLine, (i + 1) * partWidthLine, (i + 1) * partHeightLine);
        }

        primaryStage.setTitle("Draw square shaped spiral");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
    public static void downLine(Group group, double width, double height, double startWidth, double startHeight, double endWidth, double endHeight){
        Line line = new Line((width / 2) + startWidth, (height / 2) - startHeight, (width / 2) + endWidth , (height / 2) + endHeight);
        line.setStroke(Color.RED);
        line.setStrokeWidth(2);
        group.getChildren().add(line);
    }
    public static void leftLine(Group group, double width, double height, double startWidth, double startHeight, double endWidth, double endHeight){
        Line line = new Line((width / 2) + startWidth, (height / 2) + startHeight, (width / 2) - endWidth , (height / 2) + endHeight);
        line.setStroke(Color.RED);
        line.setStrokeWidth(2);
        group.getChildren().add(line);
    }
    public static void upLine(Group group, double width, double height, double startWidth, double startHeight, double endWidth, double endHeight){
        Line line = new Line((width / 2) - startWidth, (height / 2) + startHeight, (width / 2) - endWidth , (height / 2) - endHeight);
        line.setStroke(Color.RED);
        line.setStrokeWidth(2);
        group.getChildren().add(line);
    }
    public static void rightLine(Group group, double width, double height, double startWidth, double startHeight, double endWidth, double endHeight){
        Line line = new Line((width / 2) - startWidth, (height / 2) - startHeight, (width / 2) + endWidth , (height / 2) - endHeight);
        line.setStroke(Color.RED);
        line.setStrokeWidth(2);
        group.getChildren().add(line);
    }

    public static void main(String[] args) {
        launch(args);
    }
}
