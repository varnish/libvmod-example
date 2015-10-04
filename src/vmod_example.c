#include <stdio.h>
#include <stdlib.h>

#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vcc_if.h"

int
init_function(const struct vrt_ctx *ctx, struct vmod_priv *priv,
    enum vcl_event_e e)
{
	if (e != VCL_EVENT_LOAD)
		return (0);

	/* init what you need */
	return (0);
}

VCL_STRING
vmod_hello(VRT_CTX, VCL_STRING name)
{
	char *p;
	unsigned u, v;

	u = WS_Reserve(ctx->ws, 0); /* Reserve some work space */
	p = ctx->ws->f;		/* Front of workspace area */
	v = snprintf(p, u, "Hello, %s", name);
	v++;
	if (v > u) {
		/* No space, reset and leave */
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
	/* Update work space with what we've used */
	WS_Release(ctx->ws, v);
	return (p);
}
