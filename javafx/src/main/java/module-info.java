module skm.ddu.mlh {
    requires javafx.controls;
    requires javafx.fxml;

    opens skm.ddu.mlh to javafx.fxml;
    exports skm.ddu.mlh;
}
