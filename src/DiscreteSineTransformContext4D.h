#if !defined(__DISCRETESINETRANSFORMCONTEXT4D_H__)
#define __DISCRETESINETRANSFORMCONTEXT4D_H__

#include "DiscreteSineTransformContext.h"
#include "MultiDimensionalOrthogonalTransformMixin.h"
#include "TransformContext.h"

template <typename T>
using DiscreteSineTransformContext4D =
    MultiDimensionalOrthogonalTransformMixin<TransformContext<T>,
                                             DiscreteSineTransformContext<T>>;

#endif // __DISCRETESINETRANSFORMCONTEXT4D_H__
