package skm.ddu.mlh.infra.database;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

import org.junit.jupiter.api.Test;

import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class DBAccessPostgresqlTest {
    @Test
    void testConnection() {
        assertDoesNotThrow(() -> {
            DatabaseConfig cfg = DatabaseConfig.getInstance("");

            DBAccessPostgresql dbAccessPostgresql = new DBAccessPostgresql(cfg);
        });
    }

    @Test
    void testExecuteQuery() {

    }
}
