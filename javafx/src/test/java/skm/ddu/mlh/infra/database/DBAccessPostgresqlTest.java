package skm.ddu.mlh.infra.database;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.Test;

import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class DBAccessPostgresqlTest {
    @Test
    void testConnection() {
        assertDoesNotThrow(() -> {
            DatabaseConfig cfg = DatabaseConfig.getInstance("localhost:5432:postgres:fisikawangarut:skmddu_2014");

            DBAccessPostgresql dbAccessPostgresql = DBAccessPostgresql.getInstance(cfg);
            assertNotNull(dbAccessPostgresql);
        });
    }

    @Test
    void testExecuteQuery() {
        assertDoesNotThrow(() -> {
            DatabaseConfig cfg = DatabaseConfig.getInstance("localhost:5432:postgres:fisikawangarut:skmddu_2014");

            DBAccessPostgresql dbAccessPostgresql = DBAccessPostgresql.getInstance(cfg);
            assertNotNull(dbAccessPostgresql);

            assertEquals(26, dbAccessPostgresql.executeQuery("SELECT * FROM ddu_ch"));
        });
    }
}
