#include <curlpp/Easy.hpp>
#include <curlpp/Option.hpp>
#include <curlpp/cURLpp.hpp>

using namespace std;

int main()
{
    try {
        // That's all that is needed to do cleanup of used resources (RAII
        // style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<Url>("http://info.cern.ch");

        // Send request and get a result.
        // By default the result goes to standard output.
        myRequest.perform();
    }

    catch (curlpp::RuntimeError &e) {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::LogicError &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
