#!/bin/bash

if [ "$(echo $REPL_ID)" != "d9f03a71-5689-4de8-b945-af7563f37430" ]; then
  echo "This is not running in my testing enviroment. You MUST follow the build & run instructions inside of README.md"
  exit
fi

if [ "$#" -lt 2 ]; then
  echo "Usage: $0 [--run|--build] [os|installer] [-s]"
  exit 1
fi

action=$1
target=$2
flag=$3

case "$action" in
  --run)
    case "$target" in
      os)
        cp build/os/boot mnt-dysnomia
        cd mnt-dysnomia || exit
        if [ "$flag" == "-s" ]; then
          ./boot -s
        else
          ./boot
        fi
        ;;
      installer)
        if [ "$flag" == "-s" ]; then
          ./build/inst/boot --inst "$(pwd)/mnt-dysnomia" -s
          #echo "$3"
        else
          ./build/inst/boot --inst "$(pwd)/mnt-dysnomia"
         #echo "$3"
        fi
        ;;
      *)
        echo "Invalid target: $target"
        exit 1
        ;;
    esac
    ;;
  --build)
    case "$target" in
      os)
        make os
        ;;
      installer)
        make installer
        ;;
      *)
        echo "Invalid target: $target"
        exit 1
        ;;
    esac
    ;;
  *)
    echo "Invalid action: $action"
    exit 1
    ;;
esac
