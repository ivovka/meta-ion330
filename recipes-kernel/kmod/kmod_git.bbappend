do_install_append () {
	echo "options stv0900 debug=0" > ${D}${sysconfdir}/modprobe.d/stv0900-nodebug.conf
}
