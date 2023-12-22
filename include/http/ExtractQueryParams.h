#ifndef EXTRACT_QUERY_PARAMS_H
#define EXTRACT_QUERY_PARAMS_H

#include "http/httplib.h"
#include "models/BoardState.h"

BoardState extractQueryParams(const httplib::Request& req);

#endif // EXTRACT_QUERY_PARAMS_H