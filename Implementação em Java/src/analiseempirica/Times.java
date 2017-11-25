package analiseempirica;
import java.lang.management.*;

//http://nadeausoftware.com/articles/2008/03/java_tip_how_get_cpu_and_user_time_benchmarking

public class Times {
 
/** Get CPU time in nanoseconds. */
static public long getCpuTime( ) {
    ThreadMXBean bean = ManagementFactory.getThreadMXBean( );
    return bean.isCurrentThreadCpuTimeSupported( ) ?
        bean.getCurrentThreadCpuTime( ) : 0L;
}
 
/** Get user time in nanoseconds. */
static public long getUserTime( ) {
    ThreadMXBean bean = ManagementFactory.getThreadMXBean( );
    return bean.isCurrentThreadCpuTimeSupported( ) ?
        bean.getCurrentThreadUserTime( ) : 0L;
}

/** Get system time in nanoseconds. */
static public long getSystemTime( ) {
    ThreadMXBean bean = ManagementFactory.getThreadMXBean( );
    return bean.isCurrentThreadCpuTimeSupported( ) ?
        (bean.getCurrentThreadCpuTime( ) - bean.getCurrentThreadUserTime( )) : 0L;
}
}
