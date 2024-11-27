package skm.ddu.mlh;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import skm.ddu.mlh.shared.configs.ServerConfig;
import skm.ddu.mlh.views.pages.HomePage;

import java.io.IOException;

/**
 * JavaFX App
 */
public class App extends Application {

    private static Scene scene;
    private static HomePage homePage;

    @Override
    public void start(Stage stage) throws IOException {
        // scene = new Scene(loadFXML("primary"), 640, 480);
        homePage = new HomePage();
        scene = new Scene(homePage);
        // scene = new Scene(loadFXML("assets/components/ChannelInfoPage"), 640, 480);
        String cssPath = App.class.getResource("assets/css/global.css").toExternalForm();
        scene.getStylesheets().add(cssPath);
        stage.setScene(scene);
        // stage.setFullScreen(true);
        stage.show();
    }

    static void setRoot(String fxml) throws IOException {
        scene.setRoot(loadFXML(fxml));
    }

    static public void selectHomePage() throws IOException {
        scene.setRoot(homePage);
    }

    static public void selectSettingOutPage() throws IOException {
        scene.setRoot(loadFXML("assets/components/SettingOutPage"));
    }

    static public void selectChannelInfoPage() throws IOException {
        scene.setRoot(loadFXML("assets/components/ChannelInfoPage"));
    }

    private static Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void main(String[] args) {
        // test config
        ServerConfig serverConfig = ServerConfig.getInstance();

        launch();
    }

}