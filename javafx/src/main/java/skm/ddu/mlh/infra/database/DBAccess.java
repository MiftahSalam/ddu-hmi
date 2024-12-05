package skm.ddu.mlh.infra.database;

import java.sql.SQLException;
import java.util.List;

public interface DBAccess {
    public void executeUpdate(String sql) throws SQLException;

    public int executeQuery(String query) throws SQLException;

    public List<List<String>> executeQueryAndReturnResult(String query) throws SQLException;

    public void close();
}
