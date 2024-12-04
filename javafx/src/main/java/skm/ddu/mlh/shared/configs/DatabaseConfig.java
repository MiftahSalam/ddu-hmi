package skm.ddu.mlh.shared.configs;

import lombok.Getter;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@Getter
public class DatabaseConfig {
    private String host;
    private int port;
    private String username;
    private String password;
    private String name;

    private static DatabaseConfig instance;

    private DatabaseConfig(String config) throws Exception {
        String[] splitConfig = config.split(":");
        if (splitConfig.length != 5) {
            throw new Exception("invalid database config");
        }

        try {
            host = splitConfig[0];
            port = Integer.parseInt(splitConfig[1]);
            username = splitConfig[2];
            password = splitConfig[3];
            name = splitConfig[4];

        } catch (Exception e) {
            throw e;
        }
    }

    public static DatabaseConfig getInstance(String config) throws Exception {
        if (instance == null) {
            try {
                instance = new DatabaseConfig(config);
            } catch (Exception e) {
                throw e;
            }
        }

        return instance;
    }
}
