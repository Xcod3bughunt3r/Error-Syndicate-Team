#	dnsenum.pl VERSION 1.2.4
#### This version: - changed version number to the correct one	dnsenum.pl: multithread script to enumerate information on a domain and to discover non-contiguous ip blocks.
#####	1) Get the host's addresse.
#####	2) Get the nameservers (threaded).
#####	3) get the MX record (threaded).
#####	4) Perform axfr queries on nameservers (threaded).
#####	5) Get extra names via google scraping.
#####	6) Brute force subdomains from file (threaded).
#####	7) Calculate C class domain network ranges and perform whois queries on them (threaded).
#####	8) Perform reverse lookups on C class or/and whois network ranges (threaded).
#####	9) Write to domain_ips.txt file non-contiguous ip-blocks results.
#####	10) run perldoc on this script for help. To install needed modules: ``sudo perl -MCPAN -e shell`` and then e.g.: cpan[1]> install XML::Writer Special thanks to all perl developers. please see perldoc dnsenum.pl for options and arguments.

