package skm.ddu.mlh.shared.configs;

import java.io.File;

import org.apache.commons.configuration2.Configuration;
import org.apache.commons.configuration2.builder.fluent.Configurations;

import lombok.AllArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@AllArgsConstructor
@Slf4j
public class ChannelAccessConfig {
    public static enum AccessType {
        DB,
        REST_API
    }

    private static AccessType accessType;
    private static String accessConfig;
    private static ChannelAccessConfig instance;

    public static AccessType getAccessType() {
        return accessType;
    }

    public static String getAccessConfig() {
        return accessConfig;
    }

    public static ChannelAccessConfig getInstance() {
        if (instance == null) {
            Configurations configs = new Configurations();
            try {
                Configuration config = configs.properties(new File("application.properties"));

                accessType = AccessType.valueOf(config.getString("channel.access.type"));
                accessConfig = config.getString("channel.access.config");
                instance = new ChannelAccessConfig();

                log.debug("access type: " + accessType);
                log.debug("access config: " + accessConfig);
            } catch (Exception e) {
                // TODO: handle exception
                log.error("error read app config");
            }
        }

        return instance;
    }
}
