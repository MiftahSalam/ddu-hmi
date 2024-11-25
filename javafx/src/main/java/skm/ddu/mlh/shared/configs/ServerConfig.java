package skm.ddu.mlh.shared.configs;

import java.io.File;

import org.apache.commons.configuration2.Configuration;
import org.apache.commons.configuration2.builder.fluent.Configurations;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class ServerConfig {
    private String host;
    private int port;

    private static ServerConfig instance;

    private ServerConfig() {
    }

    public static ServerConfig getInstance() {
        log.debug("start method");
        if (instance == null) {
            Configurations configs = new Configurations();
            try {
                Configuration config = configs.properties(new File("application.properties"));

                log.debug("server host: " + config.getString("server.host"));
                log.debug("server port: " + config.getInteger("server.port", 0));
            } catch (Exception e) {
                // TODO: handle exception
                log.error("error read app config");
            }
            instance = new ServerConfig();
        }

        return instance;
    }
}
