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

    private DatabaseConfig(String config) {
        // TODO: temporary
        host = "localhost";
        port = 5432;
        username = "postgres";
        password = "123456";
        name = "ddu_ch";
    }

    public static DatabaseConfig getInstance(String config) {
        log.debug("start method");
        if (instance == null) {
            instance = new DatabaseConfig(config);
        }

        return instance;
    }
}
