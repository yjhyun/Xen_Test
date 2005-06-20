/****************************************************************
 * acm_null_hooks.c
 * 
 * Copyright (C) 2005 IBM Corporation
 *
 * Author:
 * Reiner Sailer <sailer@watson.ibm.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 2 of the
 * License.
 */
#include <acm/acm_hooks.h>

static int
null_init_domain_ssid(void **chwall_ssid, ssidref_t ssidref)
{
	return ACM_OK;
}


static void
null_free_domain_ssid(void *chwall_ssid)
{
	return;
}


static int
null_dump_binary_policy(u8 *buf, u16 buf_size) 
{	
	return 0;
}



static int
null_set_binary_policy(u8 *buf, u16 buf_size) 
{	
	return -1;
}

	
static int 
null_dump_stats(u8 *buf, u16 buf_size)
{
	/* no stats for NULL policy */
	return 0;
}


/* now define the hook structure similarly to LSM */
struct acm_operations acm_null_ops = {
	.init_domain_ssid		= null_init_domain_ssid,
	.free_domain_ssid		= null_free_domain_ssid,
	.dump_binary_policy           	= null_dump_binary_policy,
	.set_binary_policy		= null_set_binary_policy,
	.dump_statistics	        = null_dump_stats,
	/* domain management control hooks */
	.pre_domain_create     		= NULL,
	.post_domain_create		= NULL,
	.fail_domain_create		= NULL,
	.post_domain_destroy		= NULL,
	/* event channel control hooks */
	.pre_eventchannel_unbound      	= NULL,
	.fail_eventchannel_unbound	= NULL,
	.pre_eventchannel_interdomain	= NULL,
	.fail_eventchannel_interdomain	= NULL,
	/* grant table control hooks */
	.pre_grant_map_ref       	= NULL,
	.fail_grant_map_ref		= NULL,
	.pre_grant_setup	       	= NULL,
	.fail_grant_setup		= NULL

};
