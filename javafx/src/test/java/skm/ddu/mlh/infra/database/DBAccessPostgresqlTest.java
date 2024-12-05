package skm.ddu.mlh.infra.database;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.List;

import java.util.List;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class DBAccessPostgresqlTest {
    private static DBAccessPostgresql dbAccessPostgresql;

    @BeforeAll
    static void setup() {
        assertDoesNotThrow(() -> {
            DatabaseConfig cfg = DatabaseConfig.getInstance("localhost:5432:postgres:fisikawangarut:skmddu_2014");

            dbAccessPostgresql = DBAccessPostgresql.getInstance(cfg);
            assertNotNull(dbAccessPostgresql);
        });
    }

    @Test
    void testExecuteQuery() {
        assertDoesNotThrow(() -> {
            assertEquals(26, dbAccessPostgresql.executeQuery("SELECT * FROM ddu_ch"));
        });
    }

    @Test
    void testExecuteQueryAndReturnResult() {
        assertDoesNotThrow(() -> {
            List<List<String>> rowsResult = dbAccessPostgresql
                    .executeQueryAndReturnResult("SELECT * FROM ddu_ch WHERE ch_id=1");
            assertEquals(1, rowsResult.size());

            rowsResult.forEach(t -> {
                System.out.println("val: " + t);
            });
        });
    }

    @Test
    void testExecuteUpdate() {
        assertDoesNotThrow(() -> {
            assertEquals(1, dbAccessPostgresql.executeUpdate("UPDATE ddu_ch SET cur_data_fisis='test' WHERE ch_id=1"));
        });
    }
}
