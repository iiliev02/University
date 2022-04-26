package sample;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class Controller {
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField txtCalc;

    @FXML
    private Button btnEqual;

    @FXML
    private Button bntPlus;

    @FXML
    private Button btnMinus;

    @FXML
    private Button btnMulty;

    @FXML
    private Button btnDivided;

    @FXML
    private Button btnCa;

    @FXML
    private Button btnTwoZero;

    @FXML
    private Button btnZero;

    @FXML
    private Button btnPoint;

    @FXML
    private Button btnOne;

    @FXML
    private Button btnTwo;

    @FXML
    private Button btnThree;

    @FXML
    private Button btnFour;

    @FXML
    private Button btnFive;

    @FXML
    private Button btnSix;

    @FXML
    private Button btnSeven;

    @FXML
    private Button btnEight;

    @FXML
    private Button btnNine;

    @FXML
    private Button btnC;

    @FXML
    private Button btnMc;

    @FXML
    private Button btnM;

    @FXML
    private Button btnMPlus;

    @FXML
    private Button btnMMinus;

    @FXML
    private Button btnOff;

    private float leftNumber;
    private float equalsNumber;
    private float memoryStoredNumber;
    private String lastOperator;
    private String operator;
    private boolean clickOnSing;

    private void operations(){
        float rightNumber = 0;
        switch (operator){
            case "+": rightNumber = Float.parseFloat(txtCalc.getText());
                leftNumber += rightNumber;
                txtCalc.setText(Float.toString(leftNumber));
                break;
            case "-": rightNumber = Float.parseFloat(txtCalc.getText());
                leftNumber -= rightNumber;
                txtCalc.setText(Float.toString(leftNumber));
                break;
            case "*": rightNumber = Float.parseFloat(txtCalc.getText());
                leftNumber *= rightNumber;
                txtCalc.setText(Float.toString(leftNumber));
                break;
            case "/": rightNumber = Float.parseFloat(txtCalc.getText());
                leftNumber /= rightNumber;
                txtCalc.setText(Float.toString(leftNumber));
                break;
        }
    }

    private void kindOperation(String operator){
        if(!this.operator.equals("=") && !operator.equals("")){
            operations();
            this.operator = operator;
            clickOnSing = true;
        }else{
            leftNumber = Float.parseFloat(txtCalc.getText());
            this.operator = operator;
            clickOnSing = true;
            txtCalc.setText("");
        }
    }

    private void writeNumber(String number){
        if(txtCalc.getText() == null || txtCalc.getText().equals("0") || txtCalc.getText().equals("") || txtCalc.getText().equals("00")){
            txtCalc.setText(number);
        }else{
            if(!operator.equals("")){
                if(clickOnSing) {
                    if(txtCalc.getText().equals("0.")) {
                        String text = txtCalc.getText() + number;
                        txtCalc.setText(text);
                        clickOnSing = false;
                    }else{
                        txtCalc.setText(number);
                        clickOnSing = false;
                    }
                }else{
                    String text = txtCalc.getText() + number;
                    txtCalc.setText(text);
                }
            }else{
                String text = txtCalc.getText() + number;
                txtCalc.setText(text);
            }
        }
    }

    @FXML
    void bntPlusOnAction(ActionEvent event) {
        kindOperation("+");
    }

    @FXML
    void btnCOnAction(ActionEvent event) {
        txtCalc.setText("0");
        leftNumber = 0;
    }

    @FXML
    void btnCaOnAction(ActionEvent event) {
        String correction = txtCalc.getText();
        correction = correction.substring(0, correction.length() - 1);
        txtCalc.setText(correction);

    }

    @FXML
    void btnDividedOnAction(ActionEvent event) {
        kindOperation("/");
    }

    @FXML
    void btnEightOnAction(ActionEvent event) {
        writeNumber("8");
    }

    @FXML
    void btnEqualOnAction(ActionEvent event) {
        if (!operator.equals("=")) {
            equalsNumber = Float.parseFloat(txtCalc.getText());
            lastOperator = operator;
            operations();
        }else {
            switch (lastOperator){
                case "+": leftNumber += equalsNumber; txtCalc.setText(Float.toString(leftNumber)); break;
                case "-": leftNumber -= equalsNumber; txtCalc.setText(Float.toString(leftNumber)); break;
                case "/": leftNumber /= equalsNumber; txtCalc.setText(Float.toString(leftNumber)); break;
                case "*": leftNumber *= equalsNumber; txtCalc.setText(Float.toString(leftNumber)); break;
            }
        }
        txtCalc.setText(Float.toString(leftNumber));
        operator = "=";
        clickOnSing = true;

    }

    @FXML
    void btnFiveOnAction(ActionEvent event) {
        writeNumber("5");
    }

    @FXML
    void btnFourOnAction(ActionEvent event) {
        writeNumber("4");
    }

    @FXML
    void btnMMinusOnAction(ActionEvent event) {
        leftNumber -= memoryStoredNumber;
        txtCalc.setText(Float.toString(leftNumber));
    }

    @FXML
    void btnMOnAction(ActionEvent event) {
        memoryStoredNumber = Float.parseFloat(txtCalc.getText());
    }

    @FXML
    void btnMPlusOnAction(ActionEvent event) {
        leftNumber += memoryStoredNumber;
        txtCalc.setText(Float.toString(leftNumber));
    }

    @FXML
    void btnMcOnAction(ActionEvent event) {
        memoryStoredNumber = 0;
    }

    @FXML
    void btnMinusOnAction(ActionEvent event) {
        kindOperation("-");
    }

    @FXML
    void btnMultyOnAction(ActionEvent event) {
        kindOperation("*");
    }

    @FXML
    void btnNineOnAction(ActionEvent event) {
        writeNumber("9");
    }

    @FXML
    void btnOffOnAction(ActionEvent event) {
        if(txtCalc.getText().equals("") || txtCalc.getText() == null){
            txtCalc.setText("0");
            clickOnSing = true;
        }else{
            txtCalc.setText("");
        }
    }

    @FXML
    void btnOneOnAction(ActionEvent event) {
        writeNumber("1");
    }

    @FXML
    void btnPointOnAction(ActionEvent event) {
        if(txtCalc.getText() == null || txtCalc.getText().equals("0") || txtCalc.getText().equals("")){
            writeNumber("0.");
        }else{
            writeNumber(".");
        }
    }

    @FXML
    void btnSevenOnAction(ActionEvent event) {
        writeNumber("7");
    }

    @FXML
    void btnSixOnAction(ActionEvent event) {
        writeNumber("6");
    }

    @FXML
    void btnThreeOnAction(ActionEvent event) {
        writeNumber("3");
    }

    @FXML
    void btnTwoOnAction(ActionEvent event) {
        writeNumber("2");
    }

    @FXML
    void btnTwoZeroOnAction(ActionEvent event) {
        writeNumber("00");
    }

    @FXML
    void btnZeroOnAction(ActionEvent event) {
        writeNumber("0");
    }

    @FXML
    void initialize() {
        assert txtCalc != null : "fx:id=\"txtCalc\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnEqual != null : "fx:id=\"btnEqual\" was not injected: check your FXML file 'sample.fxml'.";
        assert bntPlus != null : "fx:id=\"bntPlus\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnMinus != null : "fx:id=\"btnMinus\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnMulty != null : "fx:id=\"btnMulty\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnDivided != null : "fx:id=\"btnDivided\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnCa != null : "fx:id=\"btnCa\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnTwoZero != null : "fx:id=\"btnTwoZero\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnZero != null : "fx:id=\"btnZero\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnPoint != null : "fx:id=\"btnPoint\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnOne != null : "fx:id=\"btnOne\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnTwo != null : "fx:id=\"btnTwo\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnThree != null : "fx:id=\"btnThree\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnFour != null : "fx:id=\"btnFour\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnFive != null : "fx:id=\"btnFive\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSix != null : "fx:id=\"btnSix\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSeven != null : "fx:id=\"btnSeven\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnEight != null : "fx:id=\"btnEight\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnNine != null : "fx:id=\"btnNine\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnC != null : "fx:id=\"btnC\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnMc != null : "fx:id=\"btnMc\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnM != null : "fx:id=\"btnM\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnMPlus != null : "fx:id=\"btnMPlus\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnMMinus != null : "fx:id=\"btnMMinus\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnOff != null : "fx:id=\"btnOff\" was not injected: check your FXML file 'sample.fxml'.";
        leftNumber = 0;
        memoryStoredNumber = 0;
        equalsNumber = 0;
        operator = "";
        lastOperator = "";
        clickOnSing = false;

    }
}
