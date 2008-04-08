#!/bin/sh
PATH=/bin:/sbin:/usr/bin:/usr/sbin; export PATH

basedir="/Library/org.pqrs/SetEjectDelay"

argument="$1"
[ -z "$argument" ] && argument=start
case "$argument" in
    start)
        echo "Starting SetEjectDelay"
        sleep 10 # wait for avoid kext loading collision.
        "$basedir/scripts/kext.sh"
        ;;

    quickstart)
        echo "Starting SetEjectDelay"
        "$basedir/scripts/kext.sh"
        ;;

    stop)
        echo "Stopping SetEjectDelay"
        "$basedir/scripts/kext.sh" unload
        ;;

    *)
        echo "Usage: $0 {start|stop}"
        ;;
esac

exit 0
