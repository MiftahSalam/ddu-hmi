package skm.ddu.mlh.shared.exceptions;

public class DDUFXMLLoadException extends DDUBaseException {
    public DDUFXMLLoadException(String message) {
        super(500, "Fail to load some fxml page with error: " + message);
    }
}
