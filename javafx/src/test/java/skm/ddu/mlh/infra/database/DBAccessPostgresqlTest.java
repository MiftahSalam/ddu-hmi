package skm.ddu.mlh.infra.database;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.Test;

import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class DBAccessPostgresqlTest {
    @Test
    void testConnection() {
        assertDoesNotThrow(() -> {
            DatabaseConfig cfg = DatabaseConfig.getInstance("localhost:5432:postgres:fisikawangarut:ddu_ch");

            DBAccessPostgresql dbAccessPostgresql = new DBAccessPostgresql(cfg);
            assertNotNull(dbAccessPostgresql);
        });
    }

    @Test
    void testExecuteQuery() {

    }
}
