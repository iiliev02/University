package sample;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class Controller {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Label lblUsernameError;

    @FXML
    private Label lblPhoneNumberError;

    @FXML
    private Label lblEmailError;

    @FXML
    private Label lblPasswordError;

    @FXML
    private TextField txtUsername;

    @FXML
    private TextField txtPhoneNumber;

    @FXML
    private TextField txtEmail;

    @FXML
    private PasswordField pswPassword;

    @FXML
    private PasswordField pswConfirmPassword;

    @FXML
    private Button btnRegistration;

    @FXML
    void btnRegistrationOnAction(ActionEvent event) {
        lblUsernameError.setText("");
        lblPhoneNumberError.setText("");
        lblEmailError.setText("");
        lblPasswordError.setText("");
        if(!txtUsername.getText().matches("[a-zA-Z]{2,}")){
            lblUsernameError.setText("Invalid username!");
        }
        if(!txtPhoneNumber.getText().matches("\\(\\d{4}\\)\\(\\d{7}\\)")){
            lblPhoneNumberError.setText("Invalid phone number!");
        }
        if(!txtEmail.getText().matches("([\\w-]+\\.?)+@[-\\w]+\\.[a-zA-Z]{2,4}")){
            lblEmailError.setText("Invalid e-mail!");
        }
        if(pswPassword.getText() == null || pswPassword.getText().equals("")){
            lblPasswordError.setText("No password");
        }
        else if(!pswPassword.getText().equals(pswConfirmPassword.getText())){
            lblPasswordError.setText("Confirm password is different");
        }

        if(lblUsernameError.getText().equals("") && lblPhoneNumberError.getText().equals("") &&
                lblEmailError.getText().equals("") && lblPasswordError.getText().equals("")){
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Successful registration");
            alert.setHeaderText("You registered an account successfully");
            alert.setContentText(null);
            alert.showAndWait();
        }
    }

    @FXML
    void initialize() {
        assert lblUsernameError != null : "fx:id=\"lblUsernameError\" was not injected: check your FXML file 'sample.fxml'.";
        assert lblPhoneNumberError != null : "fx:id=\"lblPhoneNumberError\" was not injected: check your FXML file 'sample.fxml'.";
        assert lblEmailError != null : "fx:id=\"lblEmailError\" was not injected: check your FXML file 'sample.fxml'.";
        assert lblPasswordError != null : "fx:id=\"lblPasswordError\" was not injected: check your FXML file 'sample.fxml'.";
        assert txtUsername != null : "fx:id=\"txtUsername\" was not injected: check your FXML file 'sample.fxml'.";
        assert txtPhoneNumber != null : "fx:id=\"txtPhoneNumber\" was not injected: check your FXML file 'sample.fxml'.";
        assert txtEmail != null : "fx:id=\"txtEmail\" was not injected: check your FXML file 'sample.fxml'.";
        assert pswPassword != null : "fx:id=\"pswPassword\" was not injected: check your FXML file 'sample.fxml'.";
        assert pswConfirmPassword != null : "fx:id=\"pswConfirmPassword\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnRegistration != null : "fx:id=\"btnRegistration\" was not injected: check your FXML file 'sample.fxml'.";

    }
}
