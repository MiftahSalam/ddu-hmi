package skm.ddu.mlh;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import skm.ddu.mlh.shared.configs.ChannelAccessConfig;
import skm.ddu.mlh.shared.configs.ServerConfig;
import skm.ddu.mlh.views.pages.ChannelInfoPage;
import skm.ddu.mlh.views.pages.HomePage;
import skm.ddu.mlh.views.pages.SettingInPage;
import skm.ddu.mlh.views.pages.SettingOutPage;

import java.io.IOException;

/**
 * JavaFX App
 */
public class App extends Application {

    private static Scene scene;
    private static HomePage homePage;
    private static Parent settingInPage;
    private static Parent settingOutPage;
    private static Parent channelInfoPage;
    private static SettingInPage settingInPageController;
    private static SettingOutPage settingOutPageController;
    private static ChannelInfoPage channelInfoPageController;

    @Override
    public void start(Stage stage) throws IOException {
        initPages();

        scene = new Scene(homePage);
        String cssPath = App.class.getResource("assets/css/global.css").toExternalForm();

        scene.getStylesheets().add(cssPath);
        stage.setScene(scene);
        stage.setFullScreen(true);
        stage.show();
    }

    static public void selectHomePage() throws IOException {
        scene.setRoot(homePage);
    }

    static public void selectSettingInPage(int chNum) throws IOException {
        settingInPageController.setChannel(chNum);
        scene.setRoot(settingInPage);
    }

    static public void selectSettingOutPage(int chNum) throws IOException {
        settingOutPageController.setChannel(chNum);
        scene.setRoot(settingOutPage);
    }

    static public void selectChannelInfoPage(int chNum) throws IOException {
        channelInfoPageController.setChannel(chNum);
        scene.setRoot(channelInfoPage);
    }

    private void initPages() {
        homePage = new HomePage();
        try {
            FXMLLoader settingInPageFxmlLoader = new FXMLLoader(
                    App.class.getResource("assets/components/SettingInPage.fxml"));
            FXMLLoader settingOutPageFxmlLoader = new FXMLLoader(
                    App.class.getResource("assets/components/SettingOutPage.fxml"));
            FXMLLoader channelInfoPageFxmlLoader = new FXMLLoader(
                    App.class.getResource("assets/components/ChannelInfoPage.fxml"));

            settingInPage = settingInPageFxmlLoader.load();
            settingOutPage = settingOutPageFxmlLoader.load();
            channelInfoPage = channelInfoPageFxmlLoader.load();

            settingOutPageController = settingOutPageFxmlLoader.getController();
            settingInPageController = settingInPageFxmlLoader.getController();
            channelInfoPageController = channelInfoPageFxmlLoader.getController();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        // test config
        ServerConfig serverConfig = ServerConfig.getInstance();
        ChannelAccessConfig channelAccessConfig = ChannelAccessConfig.getInstance();

        launch();
    }

}